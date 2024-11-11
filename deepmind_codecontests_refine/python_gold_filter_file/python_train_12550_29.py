
a = input().split()
delay = int(a[1])
list1=input().split()
list1.reverse()
list1 = list(map(int, list1))

final = int(a[0]) 
for i in range(len(list1)-1):
    if list1[i]-list1[i+1] > delay:
        final = i+1
        break
if len(list1) == 1:
    print(1)
else:
    print(final)
