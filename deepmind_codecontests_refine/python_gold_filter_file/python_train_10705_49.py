N = input()
print("YNeos"[bool(int(N)%sum(int(n)for n in N))::2])