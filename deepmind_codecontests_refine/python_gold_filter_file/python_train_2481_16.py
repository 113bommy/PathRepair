N=int(input())
D,X=map(int,input().split())
print(sum(1+(D-1)//int(input())for _ in[0]*N)+X)