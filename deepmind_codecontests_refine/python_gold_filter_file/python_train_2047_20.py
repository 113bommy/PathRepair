n, m, k = map(int, input().split())

'''print ('n m k')'''

if k == 0: out = '1 1'

elif k<=(n - 1): out = str(1 + k) + ' ' + '1'

elif k >= n*m:
    out = '1 2'
    
else:
    k -= n
    'print (k)'
    y = n-k//(m-1)

    
    if y%2 == 0 or y == 0:
        x = 3+(k-1-(n-y)*(m-1))
    else:
        x = m-(k-1-(n-y)*(m-1)) - 1
        
    out = str(y) + ' ' + str(x)


print (out)
