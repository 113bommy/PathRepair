N,M=map(int,input().split())
PY=[list(map(int,input().split()))+[i] for i in range(M)] #定義終了
 
PY.sort(key= lambda x:x[1])
num=[0]*N
w=[""]*M
 
for p,y,i in PY:
	num[p-1]+=1
	w[i]=str(p).zfill(6)+str(num[p-1]).zfill(6)

for i in range(M):
  	print(w[i])
