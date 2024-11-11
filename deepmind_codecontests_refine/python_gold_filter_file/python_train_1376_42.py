import re
for _ in range(int(input())):
    str= input()
    filipino= r'po$'
    japanese=r'((desu)|(masu))$'
    if re.search(filipino,str):
        print('FILIPINO')
    elif re.search(japanese,str):
        print('JAPANESE')
    else:
        print('KOREAN')
