is_debug = False

n = int(input())

t = (n*(n+1))//2
print(f"t={t}", end="|") if is_debug else ''

print(f"{t%2}")
