r,d=map(int,input().split())
n=int(input())
cnt=0
for _ in range(n):
    xt,yt,rt=map(int,input().split())
    dt=((xt)**2+(yt)**2)**0.5
    if dt-rt>=r-d and dt+rt<=r:
        cnt+=1
print(cnt)