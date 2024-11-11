n=int(input())
s=input()
st=[str(i).zfill(3)for i in range(1000)]
dp=[0]*1000
for i in s:
  for j in range(1000):
    if dp[j]<3:
      if st[j][dp[j]]==i:dp[j]+=1
print(dp.count(3))