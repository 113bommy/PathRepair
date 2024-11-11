c = [0]*10**5
for i in open(0).read().split()[2:]: c[int(i)-1] ^= 1
print("NO" if any(c) else "YES")