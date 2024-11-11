X,A,B= map(int,input().split())
print('dangerous' if X<B-A else 'safe' if B>A else'delicious')