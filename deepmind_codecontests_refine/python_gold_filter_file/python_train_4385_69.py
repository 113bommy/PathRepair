x,y,z,t1,t2,t3 = map(int, input().split())
stairs = abs(x - y) * t1
lift = abs(z - x) * t2 + t3 + t3 + abs(x - y) * t2 + t3
print('YES' if lift <= stairs else 'NO')