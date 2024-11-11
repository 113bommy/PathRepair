#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


enum Type{
	Zero,
	One,
	Tate,
	Yoko,
	Naname,
	Three,
	Four,
};


int H,N;
int ans;
int loc_sum[3][2][2];
bool table[20][2][2],fall[3][2][2][2];
Type type[3];

void copyTable(bool to[20][2][2],bool from[20][2][2]){

	for(int h = 0; h < 20; h++){
		for(int row = 0; row < 2; row++){
			for(int col = 0; col < 2; col++)to[h][row][col] = from[h][row][col];
		}
	}
}

void addBlock(bool to[20][2][2],bool add[2][2][2],int base_h){

	for(int h = 0; h < 2; h++){
		for(int row = 0; row < 2; row++){
			for(int col = 0; col < 2; col++){
				if(add[h][row][col]){
					to[base_h+h][row][col] = add[h][row][col];
				}
			}
		}
	}
}

int deleteBlock(bool tmp_table[20][2][2],int base_h){

	int ret = 0;
	int current_h = base_h,tmp_count;

	for(int i = 0; i < 2; i++){

		tmp_count = 0;
		for(int row = 0; row < 2; row++){
			for(int col = 0; col < 2; col++){
				if(tmp_table[current_h][row][col])tmp_count++;
			}
		}

		if(tmp_count == 4){ //1段下へ平行シフトする

			ret++;

			for(int h = current_h+1; h < 20; h++){
				for(int row = 0; row < 2; row++){
					for(int col = 0; col < 2; col++){
						tmp_table[h-1][row][col] = tmp_table[h][row][col];
						tmp_table[h][row][col] = false;
					}
				}
			}

			//current_hはそのまま

		}else{
			current_h++; //次の高さへ
		}
	}

	return ret;
}

void recursive(int fall_id,int num_delete,bool tmp_table[20][2][2]){

	if(fall_id == N){
		ans = max(ans,num_delete);
		return;
	}

	bool work[2][2][2];
	bool next_tmp_table[20][2][2];
	int base_h; //落下ブロックの底面となる高さ
	bool FLG;
	int next_delete;

	//fall_id番目のブロックの落下計算
	switch(type[fall_id]){
	case Zero:
		recursive(fall_id+1,num_delete,tmp_table);
		break;
	case One:

		//4箇所平行移動する
		for(int to_row = 0; to_row < 2; to_row++){
			for(int to_col = 0; to_col < 2; to_col++){

				for(int h = 0; h < 2; h++){
					for(int row = 0; row < 2; row++){
						for(int col = 0; col < 2; col++){
							work[h][row][col] = false;
						}
					}
				}

				for(int h = 0; h < 2; h++){
					for(int row = 0; row < 2; row++){
						for(int col = 0; col < 2; col++){
							if(fall[fall_id][h][row][col]){
								work[h][to_row][to_col] = true; //平行移動
							}
						}
					}
				}

				copyTable(next_tmp_table,tmp_table);
				//落下処理
				FLG = false;
				for(int h = 19; h >= 0; h--){ //落下ブロックの底面となる高さのループ
					if(h > 0){

						for(int row = 0; row < 2; row++){
							for(int col = 0; col < 2; col++){
								if((work[0][row][col] == true && next_tmp_table[h-1][row][col] == true) ||
										(work[1][row][col] == true && next_tmp_table[h][row][col] == true)){ //底面がブロックに接した場合
									FLG = true;
									break;
								}
							}
							if(FLG)break;
						}
						if(FLG){

							//全体に落下ブロックを書き足す
							base_h = h;
							addBlock(next_tmp_table,work,base_h);

							break;
						}

					}else{ //h == 0
						base_h = 0;
						addBlock(next_tmp_table,work,base_h);

						break;
					}
				}

				//消滅&落下処理
				next_delete = num_delete;
				next_delete += deleteBlock(next_tmp_table,base_h);

				//次へ
				recursive(fall_id+1,next_delete,next_tmp_table);
			}
		}
		break;
	case Tate:

		//2箇所平行移動
		for(int to_col = 0; to_col < 2; to_col++){

			for(int h = 0; h < 2; h++){
				for(int row = 0; row < 2; row++){
					for(int col = 0; col < 2; col++){
						work[h][row][col] = false;
					}
				}
			}

			for(int h = 0; h < 2; h++){
				for(int row = 0; row < 2; row++){
					for(int col = 0; col < 2; col++){
						if(fall[fall_id][h][row][col]){
							work[h][row][to_col] = true; //平行移動
						}
					}
				}
			}

			copyTable(next_tmp_table,tmp_table);
			//落下処理
			FLG = false;
			for(int h = 19; h >= 0; h--){ //落下ブロックの底面となる高さのループ
				if(h > 0){

					for(int row = 0; row < 2; row++){
						for(int col = 0; col < 2; col++){
							if((work[0][row][col] == true && next_tmp_table[h-1][row][col] == true) ||
									(work[1][row][col] == true && next_tmp_table[h][row][col] == true)){ //底面がブロックに接した場合
								FLG = true;
								break;
							}
						}
						if(FLG)break;
					}
					if(FLG){

						//全体に落下ブロックを書き足す
						base_h = h;
						addBlock(next_tmp_table,work,base_h);

						break;
					}

				}else{ //h == 0
					base_h = 0;
					addBlock(next_tmp_table,work,base_h);
					break;
				}
			}

			//消滅&落下処理
			next_delete = num_delete;
			next_delete += deleteBlock(next_tmp_table,base_h);

			//次へ
			recursive(fall_id+1,next_delete,next_tmp_table);
		}

		break;
	case Yoko:

		//2箇所平行移動
		for(int to_row = 0; to_row < 2; to_row++){

			for(int h = 0; h < 2; h++){
				for(int row = 0; row < 2; row++){
					for(int col = 0; col < 2; col++){
						work[h][row][col] = false;
					}
				}
			}

			for(int h = 0; h < 2; h++){
				for(int row = 0; row < 2; row++){
					for(int col = 0; col < 2; col++){
						if(fall[fall_id][h][row][col]){
							work[h][to_row][col] = true; //平行移動
						}
					}
				}
			}

			copyTable(next_tmp_table,tmp_table);
			//落下処理
			FLG = false;
			for(int h = 19; h >= 0; h--){ //落下ブロックの底面となる高さのループ
				if(h > 0){

					for(int row = 0; row < 2; row++){
						for(int col = 0; col < 2; col++){
							if((work[0][row][col] == true && next_tmp_table[h-1][row][col] == true) ||
									(work[1][row][col] == true && next_tmp_table[h][row][col] == true)){ //底面がブロックに接した場合
								FLG = true;
								break;
							}
						}
						if(FLG)break;
					}
					if(FLG){

						//全体に落下ブロックを書き足す
						base_h = h;
						addBlock(next_tmp_table,work,base_h);

						break;
					}

				}else{ //h == 0
					base_h = 0;
					addBlock(next_tmp_table,work,base_h);
					break;
				}
			}

			//消滅&落下処理
			next_delete = num_delete;
			next_delete += deleteBlock(next_tmp_table,base_h);

			//次へ
			recursive(fall_id+1,next_delete,next_tmp_table);

		}

		break;
	case Naname:
	case Three:
	case Four:

		copyTable(next_tmp_table,tmp_table);
		//落下処理
		FLG = false;
		for(int h = 19; h >= 0; h--){ //落下ブロックの底面となる高さのループ
			if(h > 0){

				for(int row = 0; row < 2; row++){
					for(int col = 0; col < 2; col++){
						if((fall[fall_id][0][row][col] == true && next_tmp_table[h-1][row][col] == true) ||
								(fall[fall_id][1][row][col] == true && next_tmp_table[h][row][col] == true)){ //底面がブロックに接した場合
							FLG = true;
							break;
						}
					}
					if(FLG)break;
				}
				if(FLG){

					//全体に落下ブロックを書き足す
					base_h = h;
					addBlock(next_tmp_table,fall[fall_id],base_h);

					break;
				}

			}else{ //h == 0
				base_h = 0;
				addBlock(next_tmp_table,fall[fall_id],base_h);
				break;
			}
		}

		//消滅&落下処理
		next_delete = num_delete;
		next_delete += deleteBlock(next_tmp_table,base_h);

		//次へ
		recursive(fall_id+1,next_delete,next_tmp_table);

		break;
	}
}


void func(){

	for(int h = 0; h < 20; h++){
		for(int row = 0; row < 2; row++){
			for(int col = 0; col < 2; col++)table[h][row][col] = false;
		}
	}

	char buf[3];

	//初期データの取得
	for(int h = 0; h < H; h++){
		for(int row = 1; row >= 0; row--){
			scanf("%s",buf);
			for(int col = 0; col < 2; col++){
				if(buf[col] == '#'){
					table[h][row][col] = true;
				}
			}
		}
	}

	for(int id = 0; id < 3; id++){
		for(int h = 0; h < 2; h++){
			for(int row = 0; row < 2; row++){
				for(int col = 0; col < 2; col++)fall[id][h][row][col] = false;
			}
		}
	}
	for(int id = 0; id < 3; id++){
		for(int row = 0; row < 2; row++){
			for(int col = 0; col < 2; col++){
				loc_sum[id][row][col] = 0; //鉛直方向から見下ろした際の、ブロックのある場所の数
			}
		}
	}

	int num,bottom_count;

	for(int id = 0; id < N; id++){ //塊のループ

		bottom_count = 0; //高さ0のブロックの数
		for(int h = 0; h < 2; h++){
			for(int row = 1; row >= 0; row--){
				scanf("%s",buf);
				for(int col = 0; col < 2; col++){
					if(buf[col] == '#'){
						fall[id][h][row][col] = true;
						loc_sum[id][row][col]++;
						if(h == 0)bottom_count++;
					}
				}
			}
		}
		if(bottom_count == 0){ //高さ0にブロックがない場合は、下に平行移動させておく

			for(int row = 0; row < 2; row++){
				for(int col = 0; col < 2; col++){
					fall[id][0][row][col] = fall[id][1][row][col];
					fall[id][1][row][col] = false;
				}
			}
		}


		//ブロック配置のタイプを決定する
		num = 0;
		for(int row = 0; row < 2; row++){
			for(int col = 0; col < 2; col++){
				if(loc_sum[id][row][col] > 0)num++;
			}
		}
		switch(num){
		case 0:
			type[id] = Zero;
			break;
		case 1:
			type[id] = One;
			break;
		case 2:
			if((loc_sum[id][0][0] > 0 && loc_sum[id][0][1] > 0) || (loc_sum[id][1][0] > 0 && loc_sum[id][1][1] > 0)){
				type[id] = Yoko;
			}else if((loc_sum[id][0][0] > 0 && loc_sum[1][0] > 0)||(loc_sum[id][0][1] > 0 && loc_sum[id][1][1] > 0)){
				type[id] = Tate;
			}else{
				type[id] = Naname;
			}
			break;
		case 3:
			type[id] = Three;
			break;
		case 4:
			type[id] = Four;
			break;
		}
	}

	ans = 0;

	bool first_tmp[20][2][2];

	for(int h = 0; h < 20; h++){
		for(int row = 0; row < 2; row++){
			for(int col = 0; col < 2; col++)first_tmp[h][row][col] = table[h][row][col];
		}
	}

	recursive(0,0,first_tmp);

	printf("%d\n",ans);
}


int main(){

	while(true){
		scanf("%d %d",&H,&N);
		if(H == 0 && N == 0)break;

		func();
	}

	return 0;
}

