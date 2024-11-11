fu,b=map(int,input().split())
a = input()
list1 = list(map(int,a.split()))
#list1.append(b)
list1.sort()
list2 = []
if 0 not in list1:
    list2.append(list1[0])
for i in range(len(list1)-1):
    num1 = list1[i]
    num2 = list1[i+1]
    list2.append((num2-num1)/2)
try:
    if b - list1[-1] <= max(list2):
        print(max(list2)) 
    else:
        print(b-list1[-1])
except:
    print(b)