o = list(map(int,input().split()))
#print(o)
for i in range(o[0]):
    c = input().split()
#    print(c)
    for t in c:
        if t=='M' or t=='Y'  or t=='C':
            print('#Color')
            quit()
print('#Black&White')
