def counter():#島の数をカウントする
    count=0
    #12*12個の値をひとつずつ調べる
    for x in range(len(is_data)):
        for y in range(len(is_data)):
            if is_data[x][y] == '1':#島が発見されたら
                dfs(x,y)
                count+=1
    return count
def dfs(x,y):
    if x<0 or x == len(is_data) or y<0 or y == len(is_data):
        return
    if is_data[x][y] == '1':
        is_data[x][y] = '0'
        dfs(x+1,y)
        dfs(x,y+1)
        dfs(x-1,y)
        dfs(x,y-1)

is_data=[]
while True:
    try:
        s = list(input())#入力
        if not s:#空入力のとき
            print(counter())
            is_data=[]
            s = []
        else:
            is_data.append(s)
    except EOFError:
        print(counter())
        break
