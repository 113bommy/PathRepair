F, M, S = input(), input(), input()

if F == 'rock' and M == 'scissors' and S == 'scissors' or \
        F == 'paper' and M == 'rock' and S == 'rock' or \
        F == 'scissors' and M == 'paper' and S == 'paper':
    print('F')
elif M == 'rock' and F == 'scissors' and S == 'scissors' or \
        M == 'paper' and F == 'rock' and S == 'rock' or \
        M == 'scissors' and F == 'paper' and S == 'paper':
    print('M')
elif S == 'rock' and M == 'scissors' and F == 'scissors' or \
        S == 'paper' and M == 'rock' and F == 'rock' or \
        S == 'scissors' and M == 'paper' and F == 'paper':
    print('S')
else:
    print('?')
