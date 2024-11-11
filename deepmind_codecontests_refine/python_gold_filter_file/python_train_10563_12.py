def search(li,i):
    start = 0
    end = len(li)
    while start <= end:
        mid = (start+end)//2
        if li[mid][0] == i:
            break
        elif li[mid][0] > i:
            end = mid - 1
        else:
            start = mid + 1
    if len(li[mid][0]) <= len(li[mid][1]):
        return li[mid][0]
    else:
        return li[mid][1]

def sort2(li,sent):
    li.sort(key=lambda x:x[0])
    for i in sent:
        print(search(li,i),end=' ')
        
n,m = [int(x) for x in input().split()]
li = []
for i in range(m):
    x = [x for x in input().split()]
    li.append(x)

sent = [x for x in input().split()]
sort2(li,sent)    