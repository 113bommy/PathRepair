n=int(input())
R=[int(input()) for i in range(n)]
mini=10**10
maxi=-10**10
for r in R:
    maxi=max([maxi,r-mini])
    mini=min([mini,r])
print(maxi)
