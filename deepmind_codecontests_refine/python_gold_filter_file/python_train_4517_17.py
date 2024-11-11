# bsdk idhar kya dekhne ko aaya hai, khud kr!!!
# import math
# from itertools import *
# import random
# import calendar
# import datetime
# import webbrowser

n, k = map(int, input().split())
ans = []
if k == 0:
    for i in range(1, n+1):
        ans.append(i)
    print(*ans, sep=" ")
else:
    new = 0
    for i in range(k):
        ans.append(n - i)
        new = n - i
    for i in range(1, new):
        ans.append(i)
    print(*ans, sep=" ")
