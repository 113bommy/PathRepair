n=int(input())
lst=list(set(list(map(int, input().split()))))
lst.sort()
if len(lst) > 1:
    print(lst[1])
else:
    print("NO")