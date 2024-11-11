loop = int(input())
sumss = 0
for i in range(loop):
    s = str(input())
    e = s.split(" ")
    a=0
    for j in range(len(e)):
        if e[j] =="1":
            a+=1
    if a>=2:
        sumss+=1
print(sumss)