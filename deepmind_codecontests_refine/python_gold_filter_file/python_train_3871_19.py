import atexit
import io
import sys

# _INPUT_LINES = sys.stdin.read().splitlines()
# input = iter(_INPUT_LINES).__next__
# _OUTPUT_BUFFER = io.StringIO()
# sys.stdout = _OUTPUT_BUFFER
#
#
# @atexit.register
# def write():
#     sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


R = lambda:map(int,input().split())
n,k = R()
lst1 = list(R())
id = n//2
lst1.sort()
for i in range(id,n-1):
    if (lst1[i+1]-lst1[i])*(i+1-id)>k:
        print((lst1[i]+k//(i+1-id)))
        exit()
    else:
        k-=(lst1[i+1]-lst1[i])*(i+1-id)
print(lst1[-1]+k//(n-id))
