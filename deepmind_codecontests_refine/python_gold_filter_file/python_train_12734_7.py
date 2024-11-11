n,q=map(int,input().split())
s=input()
dic={chr(i+96):i for i in range(1,27)}
presum=[dic[s[0]]]
for i in range(1,len(s)):
    presum.append(presum[i-1]+dic[s[i]])
# print(presum)
for _ in range(q):
    l,r=map(int,input().split())
    print(presum[r-1]-(presum[l-2] if l>=2 else 0))