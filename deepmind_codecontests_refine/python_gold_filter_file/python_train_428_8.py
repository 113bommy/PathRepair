num_test = int(input())
list1 = []
list2 = []
for i in range(num_test):
    list1.append(int(input()))
    list2.append([x for x in input().split()])
a = sum(list2,[])
def min_operation(s):
    try:
        first = s.index(">")
        last = len(s) - s.rindex('<')-1
        return min(first,last)
    except:
        return 0

for i in range(len(list1)):
    print(min_operation(a[i]))