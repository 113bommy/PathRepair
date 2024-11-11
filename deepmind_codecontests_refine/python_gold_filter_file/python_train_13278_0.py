n = int(input())
if n%2 == 0:
    a = ['I love it']
    for i in range(n-1):
        if i%2 ==0:
            a.append('I hate that')
        else:
            a.append('I love that')
else:
    a = ['I hate it']
    for i in range(n-1):
        if i%2 ==0:
            a.append('I love that')
        else:
            a.append('I hate that')
a.reverse()
print(' '.join(a))