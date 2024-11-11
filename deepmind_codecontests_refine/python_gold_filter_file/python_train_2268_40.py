a,b,c = map(int, input().split())
print("Yes" if len(set({a,b,c})) == 2 else "No")