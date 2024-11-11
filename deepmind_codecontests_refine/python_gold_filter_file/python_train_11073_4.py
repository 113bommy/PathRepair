# bsdk idhar kya dekhne ko aaya hai, khud kr!!!
# import math
# from itertools import *
# import random
# import calendar
# import datetime
# import webbrowser


n = int(input())
if n <= 2:
    print(-1)
else:
    arr = []
    for i in range(n, 0, -1):
        arr.append(i)
    print(*arr, sep=" ")
