n = int(input())
array = []
if n == 1:
    print(1/1)
else:
    for i in range(1,n+1):
        array.append(1/i)
    print(sum(array))