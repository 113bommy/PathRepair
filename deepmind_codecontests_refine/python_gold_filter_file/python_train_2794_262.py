a,b,c=map(int,input().split())
print('A' if min(abs(b-a),abs(c-a))==abs(b-a) else 'B')