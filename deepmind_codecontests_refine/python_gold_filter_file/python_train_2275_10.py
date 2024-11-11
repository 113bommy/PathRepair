input()
list_ = [n % 2 for n in map(int, input().rstrip("\n").split())]

print("NO" if list_.count(1) % 2 else "YES")
