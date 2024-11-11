from sys import stdin,stdout
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

n,arr = ii1(),iia()
p1 = p2 = 0
st = False
for i in range(1, n):
    if arr[i] < arr[i - 1] and not st:
        st = True
        p1 = i - 1
    if st and arr[i] > arr[i - 1]:
        p2 = i - 1
        break
if st and p1>=p2:
    p2 = n-1
arr = arr[:p1] + arr[p1: p2 + 1][::-1] + arr[p2 + 1 :]
if arr == sorted(arr) and st:
    print(p1+1,p2+1)
else:
    print(0,0)