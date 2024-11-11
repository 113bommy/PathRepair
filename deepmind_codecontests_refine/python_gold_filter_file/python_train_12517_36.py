p = str(input())
let = ['H', 'Q', '9']
if any(i in p for i in let ):
    print('YES')
else:
    print('NO')
