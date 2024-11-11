n,a=map(int, input().split())
print("YES" if sum(sorted(list(map(int, input().split())))[:-1])<=a else "NO")