import time
string = input("")
#startTime = time.time()
links = 0
pearls = 0
for i in string:
    if i == 'o':
        pearls+=1
    if i == '-':
        links+=1
if links == 0:
    print("YES")
elif links < pearls:
    print("NO")
elif pearls == 0:
    print("YES")
elif links%pearls == 0:
    print("YES")
else:
    print("NO")

#print(time.time()-startTime)
