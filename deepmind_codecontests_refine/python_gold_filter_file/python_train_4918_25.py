from sys import stdin,stdout
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

tc = ii1()
s = "abcdefghijklmnopqrstuvwxyz"
for _ in range(tc):
    n, a, b = iia()
    if n % b == 0:
        ans = s[:b] * (n // b)
    else:
        ans = (s[:b] * (n // b)) + s[:b][: n % b]
    print(ans)
    

    