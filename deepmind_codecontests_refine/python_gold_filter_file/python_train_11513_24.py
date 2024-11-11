n,k = map(int,input().split())
o = 0
for i in range(n):
    print(chr(o+97) ,end="")
    o += 1
    if o == k:
        o = 0