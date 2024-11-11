num = int(input())
win = []
dic = {}
for i in range(1,num+1):
    dic[i] = num-1
for i in range(int(num*(num-1)/2)-1):
    p = input().split()
    win.append(int(p[0]))
    dic[int(p[0])] -= 1
    dic[int(p[1])] -= 1
k = []
for i in range(1,num+1):
    if dic[i] != 0:
        k.append(i)
a = win.count(k[0])
b = win.count(k[1])
if a >= b:
    print(k[0],k[1])
else:
    print(k[1],k[0])
    

    
    
    
