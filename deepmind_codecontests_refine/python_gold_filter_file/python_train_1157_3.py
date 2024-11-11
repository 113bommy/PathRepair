n = input()
cc = input().split(" ")
sum =0
for i in range(len(cc)):
    sum = sum + (int(cc[i]) *((i)*4))
print(sum)
