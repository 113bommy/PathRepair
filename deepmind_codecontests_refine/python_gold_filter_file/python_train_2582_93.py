a,b,c = map(int, input().split())
print("Yes" if min(a,b) < c and max(a,b) > c else "No")