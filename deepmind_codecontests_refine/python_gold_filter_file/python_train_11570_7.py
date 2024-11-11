n = int(input())
count = []
for i in range(n):
    num = int(input())
    if int(num%3) == 0:
        count.append(int(num/3))
    else:
        count.append(int(num/3)+1)
for i in range(n):
    print(count[i])