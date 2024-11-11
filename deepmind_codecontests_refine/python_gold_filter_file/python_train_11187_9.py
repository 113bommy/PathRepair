n, k = map (int, input ().split ())
lst = list (map (int, input ().split ()))
x = len (lst)
for i in range (x) :
    lst [i] = [lst[i], i]
orig = k
temp = 0
ans = []
while k > 0 :
    k -= 1
    lst.sort ()
    if lst[n - 1][0] - lst[0][0] > 1 :
        lst[n - 1][0] -= 1
        lst[0][0] += 1
        ans.append ([lst[n - 1][1], lst[0][1]])
    else :
        temp += 1
lst.sort ()
k += temp
print (lst[n - 1][0] - lst[0][0], orig - k)
for i in ans :
    print (i[0] + 1, i[1] + 1)
