n = int(input())
if n % 2 == 0:
    print(n // 2, ' '.join((['2'] * (n // 2))), sep='\n')
else:
    print(n // 2 , ' '.join(['2'] * (n // 2 - 1) + ['3']), sep='\n')
