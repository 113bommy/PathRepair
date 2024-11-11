N,M=list(map(int,input().split()))
import sys
l=[list(map(int,_.rstrip().split())) for _ in sys.stdin.readlines()]
n=sorted(l,key=lambda x:x[1])
dic={}
mem=[0]*N
for i,j in n:
   mem[i-1]+=1
   dic[i,j]=str(i).zfill(6)+str(mem[i-1]).zfill(6)
for i,j in l:
   print(dic[i,j])