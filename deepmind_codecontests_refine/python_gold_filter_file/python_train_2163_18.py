N = int(input())
As = list(map(int,input().split()))

out = (sum(As)**2 - sum([a**2 for a in As]))//2
print(out % (10**9+7))