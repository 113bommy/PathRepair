import sys

money = int(sys.stdin.readline().strip().split(' ')[1])
maxmoney = money
toysStr = sys.stdin.readline().strip().split(' ') 
toys = []
for i in toysStr: toys.append(int(i));
toys.sort(reverse=True)
buy = []
smallest = toys.pop();
for i in range(1, maxmoney+1):
    if (i == smallest):
        if (len(toys)>0): smallest = toys.pop();
    else:
        if i > money: break;
        money = money - i
        buy.append(str(i))
print (len(buy))
print (" ".join(buy))