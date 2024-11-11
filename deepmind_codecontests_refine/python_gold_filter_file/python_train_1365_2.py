from bisect import bisect_right
n,d = map(int,input().split())
s = list(map(int,input().split()))
p = list(map(int,input().split()))
t_wyn = []
wyn = s[d-1]+p[0]
t_wyn.append(wyn)
del s[d-1]
s_sort = sorted(s)
p_sort = sorted(p)
p_sort.pop()
for x in range(0,len(s),+1):
    szuk = wyn-s_sort[x]-1
    if szuk < 0:
        t_wyn.append(s_sort[x]+p_sort[-1])
    else:
        pos = bisect_right(p_sort,szuk)
        if pos > 0:
            t_wyn.append(s_sort[x] + p_sort[pos-1])
            del p_sort[pos-1]
            continue
        else:
            t_wyn.append(s_sort[x] + p_sort[-1])
    p_sort.pop()
t_wyn = sorted(t_wyn)
pos = bisect_right(t_wyn,wyn)
print(n-(pos-1))