N=int(input())
A=list(map(int,input().split()))
print(1 if len([a for a in A if a>0])>=-(-N//2) else -1 if len([a for a in A if a<0])>=-(-N//2) else 0)