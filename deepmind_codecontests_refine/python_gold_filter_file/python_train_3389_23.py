n , m =map(int,input().split())
arr = []
for i in range(n):
    brr = input().split()
    arr.append(brr)
B_W = True
for item in arr:
    if 'C' in item or 'M' in item or 'Y' in item or 'C' in item:
        print("#Color")
        B_W = False
        break
if B_W:
    print("#Black&White")
    