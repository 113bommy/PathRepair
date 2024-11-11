# ヒント　dp[i]=(石の個数がi個の時直後の手番の人が勝てるか？)
n,k=map(int,input().split())
a=list(map(int,input().split()))
dp=[0]*(k+1)
for i in range(1,k+1):
    for j in range(n):
        if i-a[j]>=0 and dp[i-a[j]]==0:
            dp[i]=1
print("First" if dp[k] else "Second")