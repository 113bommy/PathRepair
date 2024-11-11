n = int(input())%360
print((abs(n-360)>45)*(n//90+int(round(n%90/90))))