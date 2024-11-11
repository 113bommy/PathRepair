n, k, p, max_p, med = map(int, input().split())
v = list(map(int, input().split()))
rem_essays= n- k
val= n//2+1- len([x for x in v if x >= med])
if val<0 and sum(v)+ rem_essays> max_p: print("-1"), exit(0)
if val>=0:
    if val*med+ rem_essays-val+ sum(v)> max_p: print("-1"), exit(0)
    if val> rem_essays: print("-1"), exit(0)
    print((str(med)+' ')*val, end='')
    print("1 "*(rem_essays- val))
if val<0: print("1 "*rem_essays)