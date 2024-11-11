s = input()
n = int(s)
num = '9'*len(s)
num = int(num)
if(2*n < num):
    num = num // 10
if (num == 0):
    print(n*(n-1)//2);
    exit(0)
ret = 0;
for i in range (9):
    tmp = str(i) + str(num)
    tmp = int(tmp);
    if (2 * n <= tmp):
        break;
    biggest = min(tmp - 1, n);
    smallest = tmp - biggest
    ret += (biggest - smallest + 1) // 2
print(ret)
# else :
#     biggest = min(num - 1, n);
#     smallest = num - biggest
#     print((biggest - smallest + 1) // 2)