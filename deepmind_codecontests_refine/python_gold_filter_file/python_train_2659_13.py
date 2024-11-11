nf, fh = map(int, input().split())
hf = list(map(int, input().split()))

#print(hf)

#print(str(hf)[1:-1])
width = 0
for i in range(nf):
    if hf[i]>fh:
        width = width + 2
    else:
        width = width + 1

print(width)