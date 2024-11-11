ip = input()
ipList = ip.split(" ")
n = int(ipList[0])
m = int(ipList[1])
k = int(ipList[2])
l = int(ipList[3])

if (k + l) % m == 0:
    x = ((k + l) // m)
else:
    x = ((k+l) // m) + 1
 
if x * m > n:
    print(-1)
else:
    print(x)