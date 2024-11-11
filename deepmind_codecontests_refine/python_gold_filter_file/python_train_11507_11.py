n = int(input())
from math import factorial as f
x = f(n)
print(x//(f(n-5)*120)+x//(f(n-6)*720)+x//(f(n-7)*5040))