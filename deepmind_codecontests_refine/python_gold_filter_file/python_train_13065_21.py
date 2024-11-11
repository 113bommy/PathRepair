'''     Design by Dinh Viet Anh(JOKER)
//_____________________________________$$$$$__
//___________________________________$$$$$$$$$
//___________________________________$$$___$
//___________________________$$$____$$$$
//_________________________$$$$$$$__$$$$$$$$$$$
//_______________________$$$$$$$$$___$$$$$$$$$$$
//_______________________$$$___$______$$$$$$$$$$
//________________$$$$__$$$$_________________$$$
//_____________$__$$$$__$$$$$$$$$$$_____$____$$$
//__________$$$___$$$$___$$$$$$$$$$$__$$$$__$$$$
//_________$$$$___$$$$$___$$$$$$$$$$__$$$$$$$$$
//____$____$$$_____$$$$__________$$$___$$$$$$$
//__$$$$__$$$$_____$$$$_____$____$$$_____$
//__$$$$__$$$_______$$$$__$$$$$$$$$$
//___$$$$$$$$$______$$$$__$$$$$$$$$
//___$$$$$$$$$$_____$$$$___$$$$$$
//___$$$$$$$$$$$_____$$$
//____$$$$$$$$$$$____$$$$
//____$$$$$__$$$$$___$$$
//____$$$$$___$$$$$$
//____$$$$$____$$$
//_____$$$$
//_____$$$$
//_____$$$$
'''
from math import *
from cmath import *
from itertools import *
from decimal import *  # su dung voi so thuc
from fractions import *  # su dung voi phan so
from sys import *
from types import CodeType, new_class
#from numpy import *

'''getcontext().prec = x # lay x-1 chu so sau giay phay (thuoc decimal)
Decimal('12.3') la 12.3 nhung Decimal(12.3) la 12.30000000012
Fraction(a) # tra ra phan so bang a (Fraction('1.23') la 123/100 Fraction(1.23) la so khac (thuoc Fraction)
a = complex(c, d) a = c + d(i) (c = a.real, d = a.imag)
a.capitalize() bien ki tu dau cua a(string) thanh chu hoa, a.lower() bien a thanh chu thuong, tuong tu voi a.upper()
a.swapcase() doi nguoc hoa thuong, a.title() bien chu hoa sau dau cach, a.replace('a', 'b', slg)
chr(i) ki tu ma i ord(c) ma ki tu c
a.join['a', 'b', 'c'] = 'a'a'b'a'c, a.strip('a') bo dau va cuoi ki tu 'a'(rstrip, lstrip)
a.split('a', slg = -1) cat theo ki tu 'a' slg lan(rsplit(), lsplit()), a.count('aa', dau = 0, cuoi= len(a)) dem slg
a.startswith('a', dau = 0, cuoi = len(a)) co bat dau bang 'a' ko(tuong tu endswith())
a.index("aa") vi tri dau tien xuat hien (rfind())
input = open(".inp", mode='r')  a = input.readline()
out = open(".out", mode='w') a.index(val) '''
#inn = open(".inp", "r")

n, m = map(int, input().split())
ans = 0
for x in range(n):
    a = input().split()
    for y in range(0, m*2, 2):
        if a[y] == '1' or a[y+1] == '1':
            ans += 1
print(ans)
