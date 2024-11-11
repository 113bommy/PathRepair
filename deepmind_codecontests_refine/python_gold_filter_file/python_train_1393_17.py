kids = int(input())+1
fingers = list(map(int,input().strip().split()))
out = 0
for i in range(1,6):
    if (sum(fingers)+i) % kids != 1:
        out+= 1
print(out)
