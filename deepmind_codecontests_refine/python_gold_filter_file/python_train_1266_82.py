######################################################
# @Author: Kaustav Vats (kaustav16048@iiitd.ac.in)
# @Roll-Number: 2016048
# @Date: Friday, June 21st 2019, 10:41:23 pm
######################################################


N = int(input())
out = 4
value = 1
for i in range(1, N):
    value += out
    out = out + 4
print(value)
