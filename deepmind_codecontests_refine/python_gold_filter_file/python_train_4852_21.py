n, theta = map(int, input().split())
phi = (n-2)*180/n
phi /= n-2
k = round(theta/phi)
k = max(k, 1)

print(f"2 1 {min(2+k, n)}")