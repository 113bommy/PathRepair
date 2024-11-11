A,V=map(int,input().split())
B,W=map(int,input().split())
T=int(input())
print(['NO','YES'][V>W and (abs(A-B)+V-W-1)//(V-W)<=T])